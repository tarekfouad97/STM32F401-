#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#define MSPI_ENABLE         1U
#define MSPI_DISABLE    0U

#define MSPI_MODE0          0U
#define MSPI_MODE1      1U
#define MSPI_MODE2           2U
#define MSPI_MODE3      3U


#define MSPI_SLAVE               0U
#define MSPI_MASTER         1U

#define MSPI_MSB_FIRST           0U
#define MSPI_LSB_FIRST      1U

#define SSM_SWITCH_CLOSE        0U
#define SSM_SWITCH_OPEN        1U

#define SSI_GND          0U
#define SSI_VCC     1U


#define MSPI_8BIT_DATA  0U 
#define MSPI_16BIT_DATA  1U


void MSPI_vInit(void);

#endif /*SPI_INTERFACE_H*/