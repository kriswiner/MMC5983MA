# MMC5983MA
Arduino sketch for 10 DoF AHRS using the MMC5983MA magnetometer

The MEMSIC [MMC5983MA](http://www.memsic.com/userfiles/files/DataSheets/Magnetic-Sensors-Datasheets/MMC5983MA_Datasheet.pdf) is an AEC-Q100 qualified complete 3-axis magnetic sensor with on-chip 
signal processing and integrated I2C/SPI bus suitable for use in automotive applications.
Coupled with the ST's [LSM6DSM]( http://www.st.com/content/ccc/resource/technical/document/datasheet/76/27/cf/88/c5/03/42/6b/DM00218116.pdf/files/DM00218116.pdf/jcr:content/translations/en.DM00218116.pdf) accel/gyro and [LPS22HB](http://www.st.com/content/ccc/resource/technical/document/datasheet/bf/c1/4f/23/61/17/44/8a/DM00140895.pdf/files/DM00140895.pdf/jcr:content/translations/en.DM00140895.pdf) barometer the system provides a compact an accurate absolute orientation estimation engine.
 
Uses the I2C interface for data transfer.
 
Intended to be run on a Dragonfly development board:

 https://www.tindie.com/products/tleracorp/dragonfly-stm32l47696-development-board/
 
 ![breadboard image](https://user-images.githubusercontent.com/6698410/85341294-a71fd300-b49c-11ea-8dcb-131431fecc0f.jpg)
   
