/* gpio_api.h - General Purpose Input/Output API
*/

#ifndef MSP_GPIO_API_H
#define MSP_GPIO_API_H

#include  <msp430g2553.h>

#define INPUT   0
#define OUTPUT  1

/* gpio_init - initialize GPIO pin
 * @param port (1,2)
 * @param pin  (0-7)
 * @param direction (INPUT or OUTPUT), (0, 1)
 * @returns true if configured, else false if error
 */
void gpio_init (int port, int pin, int direction);

/* gpio_write - write to GPIO pin
 * @param port (1,2)
 * @param pin  (0-7)
 * @param value (0,1)
 * @returns true if set, else false if error
 */
void gpio_write(int port, int pin, int value);

/* gpio_read - write to GPIO pin
 * @param port (1,2)
 * @param pin  (0-7)
 * @returns 1 if set
            0 if unset
            -1 if error
 */
int  gpio_read (int port, int pin);

#endif