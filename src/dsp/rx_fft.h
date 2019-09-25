#ifndef RX_FFT_H
#define RX_FFT_H

#include <uhd/usrp/multi_usrp.hpp>
#include <fftw3.h>
#include <iostream>

#define SAMPLE_PER_BUFF 4096

class rx_fft 
{

public:
    rx_fft(void);
    ~rx_fft();

    float* get_fft_data(uhd::usrp::multi_usrp::sptr &usrp);

private:

	fftw_complex *in;
    fftw_complex *out;
    fftw_plan p;
	
	std::complex<float> iq_data_buff[SAMPLE_PER_BUFF];           /*save IQ data*/
	float           d_realFftData[SAMPLE_PER_BUFF];   			 /* save FFT data */
	float           fftPeakHoldBuf[SAMPLE_PER_BUFF] ; 			/* save FFT peak data */

	double pt_real,pt_imag;

    float           pwr;
    float           pwr_scale;

	uhd::rx_metadata_t md;
	
};


#endif // RX_FFT_H



