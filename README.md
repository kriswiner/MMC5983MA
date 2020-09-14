# MMC5983MA
Arduino sketch for 10 DoF AHRS using the MMC5983MA magnetometer

The MEMSIC [MMC5983MA](http://www.memsic.com/uploadfiles/2020/08/20200827165332520.pdf) is an AEC-Q100 qualified complete 3-axis magnetic sensor with on-chip signal processing and integrated I2C/SPI bus suitable for use in automotive applications. Coupled with the ST [LSM6DSM]( http://www.st.com/content/ccc/resource/technical/document/datasheet/76/27/cf/88/c5/03/42/6b/DM00218116.pdf/files/DM00218116.pdf/jcr:content/translations/en.DM00218116.pdf) accel/gyro and [LPS22HB](http://www.st.com/content/ccc/resource/technical/document/datasheet/bf/c1/4f/23/61/17/44/8a/DM00140895.pdf/files/DM00140895.pdf/jcr:content/translations/en.DM00140895.pdf) barometer the system provides a compact and accurate absolute orientation estimation engine.

We are getting pretty good [results](https://hackaday.io/project/160283/log/182097-max32660-motion-coprocessor-mmc5983ma-low-noise-magnetometer-results) with this magnetometer!
 
Uses the I2C interface at 400 kHz for data transfer.
 
Intended to be run on a [Dragonfly](https://www.tindie.com/products/tleracorp/dragonfly-stm32l47696-development-board/) development board.
 
Breakout board design [files](https://oshpark.com/shared_projects/dQtm1Bbl) are open-source and available in the OSH Park shared space.

![breadboard image](https://user-images.githubusercontent.com/6698410/85341294-a71fd300-b49c-11ea-8dcb-131431fecc0f.jpg)

Copyright 2020 Tlera Corporation. May be used by anyone with proper attribution.
 
   
