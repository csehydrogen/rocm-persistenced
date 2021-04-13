# rocm-persistenced

## Background

Modern GPUs go into "sleep mode" when no process is using the devices. Whenever you use them, device initialization incurs significant overhead. For example, it takes **30 seconds** to wake up 8 GPUs in my system.

```bash
$ time /opt/rocm/bin/rocm-smi
======================= ROCm System Management Interface =======================
================================= Concise Info =================================
GPU  Temp   AvgPwr  SCLK    MCLK    Fan   Perf  PwrCap  VRAM%  GPU%  
0    30.0c  20.0W   800Mhz  100Mhz  0.0%  auto  195.0W    0%   40%   
(...)
7    30.0c  22.0W   800Mhz  100Mhz  0.0%  auto  195.0W    0%   33%   
================================================================================
============================= End of ROCm SMI Log ==============================
real	0m29.134s
user	0m0.108s
sys	0m26.017s
```

This overhead is annoying and unacceptable. NVIDIA provides **persistent mode** which prevents the device from sleeping. You can enable it with `nvidia-smi -pm 1`. However, ROCm does not provide such functionality.

Simple solution would be running a process that holds device handles and never exits. That is what this daemon does.

## Install

```bash
$ # First, download and unzip the release
$ ./configure --prefix=/opt/rocm-persistenced CPPFLAGS=-I/path/to/opencl/include LDFLAGS=-L/path/to/opencl/lib
$ make
$ sudo make install
$ systemctl enable rocm-persistenced
$ systemctl start rocm-persistenced
```

## Uninstall

```bash
$ systemctl stop rocm-persistenced
$ systemctl disable rocm-persistenced
$ sudo make uninstall
```

## Distribute (only for developer)

```bash
$ aclocal
$ autoconf
$ automake --add-missing
$ ./configure
$ make dist
```
