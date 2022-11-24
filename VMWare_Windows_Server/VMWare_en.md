![WS logo](https://i.imgur.com/ZppywgW.jpg)
![VMWare logo](https://i.imgur.com/cCOzJl0.jpg)

# VMWare Workstation Pro 16.x (and above) and Windows Server Standard Edition 2019 (and above) (Desktop Experience) tutorials and issues solving !

The purpose of this page is to explain how to perform a correct installation of Windows Server Standard Edition 2019 (and above) (Desktop Experience) and similar on VMWare Workstation Pro 16.x (and above) and correcting potential bugs that can occurs !
Please not that this page will not cover ESXi version !

## Disclaimer !!

"This tutorial is provided to you by two student of the ESGI Paris School and was done in a study-like environment.
Some elements may need to be reviewed and cleared in order to be fully effective in professional environment ! (For safety purpose)"

Melissa Gries (@CadenEras)

## Covering

Note that as written above, this page will fully cover the mentioned version of windows but is also valid for the following :

- Windows Server 2019 Standard Edition (Desktop Experience)
- Windows Server 2019 Data Center Edition (Desktop Experience)
- Windows Server 2022 Standard Edition (Desktop Experience)
- Windows Server 2022 Data Center Edition (Desktop Experience)

Another page will be dedicated to Windows Server Core Edition.
This tutorial is runned on VMWare Worksation Pro 17 but is fully compatible with 16 and 16.2 version.

If you looking for issue solving, check Issues page to see if your question is answered or feel free to open one.

Subjects covered here are :
    -Installation of Windows Server and hardware configuration
    -Optimization Server/VM
    -Securing Server with TPM and Bitlocker
    -Configuring network (Static IP, Gateway, DNS, double network interfaces)
    -Creating and deploying Active Directory
    -Group Policies
    -DNS record
    -Configuring DHCP server
    -Client deployment with Windows Deployment Services (WDS)
    -Active Directory Read-Only Domain Controller (RODC) deployment

(Subjects may be updated with time)

## Context of the tutorial and details on the writting

When my friend and I were on our Windows Administration course, our Professor gave us practical work and (since the last course we had for this subject was last year) it gave us a hard time because we noticed that we've forgotten a lot of critical things to correctly finish this work. So as time goes by, we decided to make this tutorial so that now we have a place were we can search and remember what we need and we each other tought that it will help some people that ask themself some question they cannot answer because solution on internet are sometimes not that clear... 

The images and screenshot used here will be mostly hosted on https://imgur.com/ .

For this tutorial, I (@CadenEras) ran the exemple you will see beside on my computer with the following configuration :

Lenono ThinkPad L15 Gen 3 21C3CTO1WW Laptop
x64-based PC
OS Microsoft Windows 11 Home Version 10.0.22621 Build 22621
Processor 12th Gen Intel(R) Core(TM) i7-1255U, 1700Mhz, 10 Core(s), 12 Logicale Processors (Virtualization enabled)
Installed RAM 32,0 GB (31,7 GB) 3200Mhz SODIMM
954 GB SSD
Intel(R) Iris(R) Xe Graphics

VMWare Workstation Pro 17

## Sources

A lot of sources will be written here so you can see more details by yourself. Most of our sources comes from https://learn.microsoft.com/en-us/windows-server https://kb.vmware.com/ https://docs.vmware.com/ and https://communities.vmware.com/ . The last ressources comes from our courses but are only available in French.

Let's get started !

### Minimum requirement for VMWare Worksation Pro 16.x and above

In this tutorial, we'd assume that you have already VMWare Workstation installed, but if not or if you are looking for issue solving, here's minimum requirement for 16.x to 17.x version :

Workstation 16.x and 17.x requires a 64-bit operating system on the host PC. You can still run 32-bit Windows and Linux guest operating systems inside a virtual machine on Workstation 15 Pro and above.

A compatible 64-bit x86/AMD64 CPU launched in 2011 or later *
-1.3GHz or faster core speed
-2GB RAM minimum/ 4GB RAM or more recommended
    General Host OS Requirements
        VMware Workstation Pro and Player run on most 64-bit Windows or Linux host operating systems:
            -Windows 11 (Workstation Pro 17.x only !!)
            -Windows 10, 8
            -Windows Server 2019, 2016, 2012
            -Ubuntu
            -Red Hat Enterprise Linux
            -CentOS
            -Oracle Linux
            -openSUSE
            -SUSE Linux Enterprise Server
        Note: Windows 7 hosts are no longer supported, Workstation 16.x and 17.x will not function on them.

Workstation Pro installation: 
-1.2 GB of available disk space for the application
-Additional hard disk space is required for each virtual machine
-Please refer to the vendor's recommended disk space for specific guest operating systems

Supported Guest Operating Systems
VMware Workstation 16.x and 17.x supports hundreds of 32-bit and 64-bit guest operating systems. 
Here is a list of the most popular:
    -Windows 11, 10, 8, 7, XP
    -Ubuntu
    -RedHat
    -SUSE
    -Oracle Linux
    -Debian
    -Fedora
    -openSUSE
    -Mint
    -CentOS
    -Solaris, FreeBSD, and various other Linux Distros
See the VMware Compatibility Guide for a complete list of supported host and guest operating systems.

For Hyper-V Enabled Hosts
    CPU Requirements:
        -Intel Sandy Bridge or a newer CPU
        -AMD Bulldozer or a newer CPU
    Host Operating Systems:
        -Windows 10 2004
    For 3D Hardware Accelerated Graphics Support:

        Hardware Requirements:
            -For Windows hosts, a GPU that supports DirectX 11.1 is required. 
            -For Linux hosts, the latest NVIDIA proprietary drivers are required. 
            -For Linux hosts, AMD devices are not supported
        Software Requirements:
            -64-bit Host Operating System:
            -Windows 8 or higher
            -GNU/Linux with NVIDIA drivers that support OpenGL 4.5 and above
            -Guest Operating System
            -Windows 7 or higher
            -GNU/Linux with vmwgfx 
        With the exception, the following CPUs are not supported:
            -Intel Atom processors based on the 2011 “Bonnell” micro-architecture (e.g. Atom Z670/Z650; Atom N570)
            -Systems using Intel Atom processors based on the 2012 “Saltwell” micro-architecture (e.g. Atom S1200, Atom D2700/D2500, Atom N2800/N2600.
            -Systems using AMD processors based on the “Llano” and “Bobcat” micro-architectures (e.g. code-named “Hondo”, “Ontario”, “Zacate”, “Llano”)
            -In addition, the following CPUs are supported:
            -Intel processors based on the 2010 “Westmere” micro-architecture (e.g. Xeon 5600, Xeon 3600, Core i7-970, Core i7-980, Core i7-990)

### Minimum requirement for Windows Server 2019 and above installation on a virtual machine

Beware that what is stated beside is the absolute minimum to successfully install Windows Server (Core Edition) on a VM and should not be considered as what you want to use in any environment ! For more information, refer to the Microsoft documentation.

Processor :
    -1.4 GHz 64-bit processor
    -Compatible with x64 instruction set
    -Supports NX and DEP
    -Supports CMPXCHG16b, LAHF/SAHF, and PrefetchW
    -Supports Second Level Address Translation (EPT or NPT)

RAM :
    -800 MB (2 GB for Server with Desktop Experience installation option)
    -ECC (Error Correcting Code) type or similar technology, for physical host deployments

Disk Space :
    -32 GB minimum
    Windows Server does not allow ATA/PATA/IDE/EIDE for boot, page, or data drives.

Network adapter
    -An ethernet adapter capable of at least 1 gigabit per second throughput
    -Compliant with the PCI Express architecture specification.

Other requirements :
    -DVD drive (if you intend to install the operating system from DVD media)

    The following items are only required for certain features:
        -UEFI 2.3.1c-based system and firmware that supports secure boot
        -Trusted Platform Module
        -Graphics device and monitor capable of Super VGA (1024 x 768) or higher-resolution
        -Keyboard and Microsoft mouse (or other compatible pointing device)
        -Internet access (fees may apply)

         Note:
            A Trusted Platform Module (TPM) chip is required in order to use certain features such as BitLocker Drive Encryption. If your computer uses TPM, it must meet these requirements:

            -Hardware-based TPMs must implement version 2.0 of the TPM specification.
            -TPMs that implement version 2.0 must have an EK certificate that is either pre-provisioned to the TPM by the hardware vendor or be capable of being retrieved by the device during the first boot.
            -TPMs that implement version 2.0 must ship with SHA-256 PCR banks and implement PCRs 0 through 23 for SHA-256. It is acceptable to ship TPMs with a single switchable PCR bank that can be used for both SHA-1 and SHA-256 measurements.
            A UEFI option to turn off the TPM is not a requirement.