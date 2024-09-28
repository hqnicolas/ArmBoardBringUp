1. Driver part
# get the driver
clone git fork: https://github.com/kulica/linux_openvfd

# install kernel-headers from armbian-config

sudo ln -sf /boot/System.map-$(uname -r) /lib/modules/$(uname -r)/build/System.map 

# change the directory to git clone
cd linux_openvfd/driver

# compile the modified driver (in openvfd/driver):
make -j4

# install module
sudo make modules_install

# load module
sudo modprobe openvfd

2. Install OpenVFDService
cd linux_openvfd
make -j4 OpenVFDService
sudo cp OpenVFDService /usr/sbin/
sudo chmod 777 /usr/sbin/OpenVFDService

3. Make sure your DTB contains fddis_dev node

4. Copy openvfd.service to /lib/systemd/system/openvfd.service

5. copy openvfd tree overylay
sudo armbian-add-overlay openvfd-enable.dts
sudo reboot

6. Copy setting over to the eMMC
sudo cp openvfd.conf /etc/modprobe.d/

7. enable service and start (this will autoload the kernel module openvfd
sudo systemctl enable openvfd
sudo systemctl start openvfd

After this the system clock will successfully show up on the front LCD
