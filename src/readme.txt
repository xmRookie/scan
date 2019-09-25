
1、整体代码框架：
src
├── app                
│   ├── CMakeLists.txt
│   ├── receiver.cpp      
│   └── receiver.h
├── CMakeLists.txt
├── dsp
│   ├── CMakeLists.txt
│   ├── rx_fft.cpp
│   └── rx_fft.h
└── main.cpp       

2、编译方法：
  在src目录下：
    sudo mkdir build
    sudo cmake ../
    sudo make

3、运行程序:
    cd build
    ./src arg1  ## arg1为扫描中心频率，例如./src 103e6,传入中心频率值103MHz，程序运行结束后，会在/tmp目录下生成data.dat，保存fft数据

