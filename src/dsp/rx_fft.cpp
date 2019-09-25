#include <fstream>
#include <cmath>
#include "rx_fft.h"

#define SAMPLE_TIMES 10000        /* limit uint_32 */

rx_fft::rx_fft(void)
{
	in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * SAMPLE_PER_BUFF);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * SAMPLE_PER_BUFF);
	//fftw_plan p;
}

rx_fft::~rx_fft()
{
	fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out );
}

/**
 * brief	: Converting Baseband Signal to FFT data
 * param	: 
 * return	: Power Value in dBFS
 */
float * rx_fft::get_fft_data(uhd::usrp::multi_usrp::sptr &usrp)
{ 
	std::string cpu_format = "fc32";   			//fc32   -     	complex<float>
    std::string wire_format = "sc16";           //sc16	 -		complex<int16_t>
	uhd::stream_args_t stream_args(cpu_format, wire_format);
	
	uhd::stream_cmd_t stream_cmd(uhd::stream_cmd_t::STREAM_MODE_START_CONTINUOUS);
	stream_cmd.num_samps = SAMPLE_PER_BUFF;
    stream_cmd.stream_now = true;
	stream_cmd.time_spec = usrp->get_time_now();
	
    uhd::rx_streamer::sptr rx_stream = usrp->get_rx_stream(stream_args);
    rx_stream->issue_stream_cmd(stream_cmd);
	
	memset(fftPeakHoldBuf, 0, SAMPLE_PER_BUFF * sizeof(float));

	 /*open file save IQ or FFT data*/
    std::ofstream outfile;
    outfile.open("/tmp/data.dat",std::ios::out | std::ios::trunc);

	for(uint32_t times = 0; times < SAMPLE_TIMES; times++){

		memset(iq_data_buff, 0, SAMPLE_PER_BUFF * sizeof(std::complex<float>));
		rx_stream->recv(iq_data_buff, SAMPLE_PER_BUFF, md, 3.0, false);

		for (uint32_t i = 0; i < SAMPLE_PER_BUFF; i++){
	        in[i][0] = iq_data_buff[i].real();
	        in[i][1] = iq_data_buff[i].imag();
	    }
		
		p = fftw_plan_dft_1d(SAMPLE_PER_BUFF,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
		fftw_execute(p);	/* compute FFT */

	    pwr_scale = 1.0 / ((float)SAMPLE_PER_BUFF * (float)SAMPLE_PER_BUFF);

	    /* Normalize, calculate power and shift the FFT */
	    for (uint32_t i = 0; i < SAMPLE_PER_BUFF; i++)
	    {
	        /* normalize and shift */
	        if (i < SAMPLE_PER_BUFF/2) {
	            pt_real = out[SAMPLE_PER_BUFF/2+i][0];
	            pt_imag = out[SAMPLE_PER_BUFF/2+i][1];
	        }else{
	            pt_real = out[i-SAMPLE_PER_BUFF/2][0];
	            pt_imag = out[i-SAMPLE_PER_BUFF/2][1];
	        }

	        /* calculate power in dBFS */
	        pwr = pwr_scale * (pt_real * pt_real + pt_imag * pt_imag);

	        d_realFftData[i] = 10.0 * log10f(pwr + 1.0e-20);

			/* compare FFT data , update FFT peak */
			if(times){	
				if( d_realFftData[i] > fftPeakHoldBuf[i] ){
					fftPeakHoldBuf[i] = d_realFftData[i]; 	
				}
			}else{
				fftPeakHoldBuf[i] = d_realFftData[i];	/* based on the first FFT data */
			}
			
	        //std::cout << d_realFftData[i];

	        /* FFT averaging */
	        // d_iirFftData[i] += d_fftAvg * (d_realFftData[i] - d_iirFftData[i]);
	    }
	}

	for(uint32_t i = 0; i < SAMPLE_PER_BUFF; i++){
		outfile << fftPeakHoldBuf[i] << "\n"; 	/*write FFT peak to file*/
	}

	stream_cmd.stream_mode = uhd::stream_cmd_t::STREAM_MODE_STOP_CONTINUOUS;
	rx_stream->issue_stream_cmd(stream_cmd);

	outfile.close();
	
	return d_realFftData;
}




