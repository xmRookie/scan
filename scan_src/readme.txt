
1、整体代码框架：
.
├── app
│   ├── CMakeLists.txt
│   ├── receiver.cpp
│   └── receiver.h
├── build.sh                
├── CMakeLists.txt
├── dsp
│   ├── CMakeLists.txt
│   ├── rx_fft.cpp
│   └── rx_fft.h
├── main.cpp
├── readme.txt
└── target                   
    ├── scan
    ├── scan_update.tar.bz2
    └── update_scan.sh
    

2、编译方法：
	A、自动编译：
		./build.sh compile
	B、手动编译
  		在scan_src目录下：
		sudo rm -r build
    	sudo mkdir build
    	cd build
    	sudo cmake ../
    	sudo make

3、运行程序:
    cd build
    ./scan arg1  ## arg1为扫描中心频率，例如./src 103e6,传入中心频率值103MHz，程序运行结束后，会在/tmp目录下生成data.dat，保存fft数据

