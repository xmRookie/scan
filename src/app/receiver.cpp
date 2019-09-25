#include <iostream>
#include "receiver.h"

#define SAMPLE_RATE 	20e6
//#define CENTER_FREQ 	1860e6
#define RX_GAIN			40
#define RX_BW			20e6

receiver::receiver(void)
{
	
}


receiver::~receiver()
{

}

/**
 * brief	: initialization receiver
 * param	: 
 */
void receiver::init(receiver &init, double cent_frq)
{
	std::string addr_args = " ";
    usrp = uhd::usrp::multi_usrp::make(addr_args);

	std::string ref = "internal"; 
	init.set_clock_source(ref);
	
	init.set_master_clock_rate(40e6);
	printf("set the clock rate to %0.2f MHz\n", init.get_master_clock_rate() / 1e6);

	init.set_Input_rate(SAMPLE_RATE);
	printf("set the rx sample rate to %0.2f MHz\n", init.get_Input_rate() / 1e6 );

	std::string subdev("A:B");
	init.set_rx_subdev_spec(subdev);
	
	//init.set_rf_freq(CENTER_FREQ);
	init.set_rf_freq(cent_frq);
	printf("set the rx center freq to %0.2f MHz\n",  init.get_rf_freq() / 1e6 );
	
	init.set_rx_gain(RX_GAIN);
	printf("set the rx gain to %0.2f \n", init.get_rx_gain());
	
	init.set_antenna("RX2");
	std::cout << "set the rx antenna to " << init.get_antennas() << std::endl;
	
	init.set_rx_bandwidth(RX_BW);
	printf("set the rx bandwidth to %0.2f MHz\n", init.get_rx_bandwidth() / 1e6);

}


/**
 * brief	: Set clock source .
 * param	: ref in internal  / external  / MIMO
 */
void receiver::set_clock_source(std :: string ref)
{
    usrp->set_clock_source(ref);
}

/**
 * brief	: Set the RX frontend specification .
 * param	: subdev in "A:A" or "A:B"
 */
void receiver::set_rx_subdev_spec(std :: string subdev)
{
    usrp->set_rx_subdev_spec(subdev);
}


/**
 * brief	: Set master clock rate .
 * param	: clock_rate The desired clock_rate in Hz
 */
void receiver::set_master_clock_rate(double clock_rate)
{
	usrp->set_master_clock_rate(clock_rate);
}

/**
 * brief	: Get master clock rate .
 * return	: The actual master clock rate 
 */
double receiver::get_master_clock_rate(void)
{
	usrp->get_master_clock_rate();
}

/**
 * brief	: Set rx antenna .
 * param	: antenna The desired antenna : TX/RX  or RX2
 */
void receiver::set_antenna(const std :: string & antenna)
{
	usrp->set_rx_antenna(antenna);
}

/**
 * brief	: Get the antenna currently in use.
 * return	: Name of antenna 
 */
std::string receiver::get_antennas(void)
{
	return usrp->get_rx_antenna();
}

/**
 * brief	: Set input rate .
 * param	: rate The desired input rate in Hz
 */
void receiver::set_Input_rate(double rate)
{
	usrp->set_rx_rate(rate);
}

/**
 * brief	: Get the input rate
 * return	: The actual input rate
 */
double receiver::get_Input_rate(void)
{
	return usrp->get_rx_rate();
}


/**
 * brief	: Set rx bandwidth .
 * param	: rate The desired rx bandwidth in Hz
 */
void receiver::set_rx_bandwidth(double bw)
{
	usrp->set_rx_bandwidth(bw);
}

/**
 * brief	: Get the rx bandwidth
 * return	: The actual rx bandwidth
 */
double receiver::get_rx_bandwidth(void)
{
	return usrp->get_rx_bandwidth();
}


/**
 * brief	: Set rx gain .
 * param	: value The desired rx gain in dB
 */
void receiver::set_rx_gain(double value)
{
	usrp->set_rx_gain(value);
}

/**
 * brief	: Get the rx gain
 * return	: The actual rx gain
 */
double receiver::get_rx_gain(void)
{
	return usrp->get_rx_gain();
}

/**
 * brief	: Set rx center frequency .
 * param	: rate The desired rx center frequency in Hz
 */
void receiver::set_rf_freq(double freq_hz)
{
	usrp->set_rx_freq(freq_hz);
}

/**
 * brief	: Get the rx center frequency
 * return	: The actual rx center frequency
 */
double receiver::get_rf_freq(void)
{
	return usrp->get_rx_freq();
}





