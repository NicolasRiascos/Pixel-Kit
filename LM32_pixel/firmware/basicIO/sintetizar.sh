cd ~/Documentos/Embebidos2018-2/lm32_pixel/firmware/basicIO
make clean
make
cd ../..
sudo make clean
sudo make clean
make
scp ~/Documentos/Embebidos2018-2/lm32_pixel/system.bit pi@169.254.70.29:~/Desktop

