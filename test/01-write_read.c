
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "loribu.h"

int main(void)
{
    loribu_t *rb = loribu_create(LORIBU_CREATE_BUFFER, 512);

    if (!rb)
        return 1;

    const char data[] = "hello world";
    int n = loribu_write(rb, (uint8_t *) data, sizeof data);
    assert(n == sizeof data);

    uint8_t buffer[128];
    int m = loribu_read(rb, buffer, n);
    assert(n == m);

    n = loribu_write(rb, (uint8_t *) data, strlen(data));
    n += loribu_write(rb, (uint8_t *) data, strlen(data) + 1);
    m = loribu_read_until(rb, buffer, sizeof buffer, 0);
    assert(n == m);

    loribu_destroy(rb);

    return 0;
}
