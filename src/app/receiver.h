#ifndef RECEIVER_H
#define RECEIVER_H

#include <uhd/usrp/multi_usrp.hpp>
#include <iostream>
#include <string>

class receiver
{

public:

    receiver(void);
    ~receiver();

	void			init(receiver &init, double cent_frq);
    
	void  			set_clock_source(std::string ref);
	void			set_rx_subdev_spec(std::string subdev);
	
	void 			set_master_clock_rate(double clock_rate);
	double			get_master_clock_rate(void);
	
    void        	set_antenna(const std::string &antenna);
	std::string 	get_antennas(void) ;

    void      		set_Input_rate(double rate);
    double      	get_Input_rate(void) ;

    void      		set_rx_bandwidth(double bw);
    double      	get_rx_bandwidth(void) ;

    void     		set_rf_freq(double freq_hz);
    double      	get_rf_freq(void);
	
    void      		set_rx_gain(double value);
    double      	get_rx_gain(void) ;

//private:	
    uhd::usrp::multi_usrp::sptr     usrp;       /*!< Real time I/Q source. */
    
};


#endif // RECEIVER_H


