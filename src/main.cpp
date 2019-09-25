#include <uhd/usrp/multi_usrp.hpp>
#include <csignal>
#include <fftw3.h>
#include <fstream>
#include <stdlib.h>
#include "app/receiver.h"
#include "dsp/rx_fft.h"

int main(int argc, char * argv[] )
{
	double frq = 875e6;

	frq = atof(argv[1]);	/* receive external variables : center frquency */
	if(frq > 6e9 || frq < 70e6 ){
		std::cout << "The center frequency must be between 70MHz and 6Ghz." <<std::endl;
		return 1;
	}

	receiver my_usrp;
	rx_fft rx;

	my_usrp.init(my_usrp,frq);
	rx.get_fft_data(my_usrp.usrp);

	return 0;
}

