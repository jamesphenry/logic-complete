#include <stdint.h>
#include <stddef.h>

#include "unity.h"
#include "address_map.h"

typedef struct
{
    uint8_t data[10];

    size_t last_address;
    uint8_t last_value;
    uint8_t write_count;
} TestDevice;

uint8_t test_device_read(
    void *context,
    size_t address)
{
    TestDevice *device = context;

    device->last_address = address;

    return device->data[address];
}

void test_device_write(
    void *context,
    size_t address,
    uint8_t value)
{
    TestDevice *device = context;

    device->last_address = address;
    device->last_value = value;
    device->write_count++;

    device->data[address] = value;
}

void test_address_map(void)
{
    TestDevice device =
    {
        .data =
        {
            10, 20, 30, 40, 50,
            60, 70, 80, 90, 100
        }
    };

    AddressMapEntry entry =
    {
        .start = 100,
        .size = 10,

        .context = &device,

        .read = test_device_read,
        .write = test_device_write
    };

    TEST_ASSERT_EQUAL_UINT8(
        10,
        address_map_read(&entry, 100));

    TEST_ASSERT_EQUAL_UINT32(
        0,
        device.last_address);

    TEST_ASSERT_EQUAL_UINT8(
        60,
        address_map_read(&entry, 105));

    TEST_ASSERT_EQUAL_UINT32(
        5,
        device.last_address);

    TEST_ASSERT_EQUAL_UINT8(
        100,
        address_map_read(&entry, 109));

    TEST_ASSERT_EQUAL_UINT32(
        9,
        device.last_address);

    TEST_ASSERT_EQUAL_UINT8(
        0,
        address_map_read(&entry, 99));

    TEST_ASSERT_EQUAL_UINT8(
        0,
        address_map_read(&entry, 110));

    address_map_write(
        &entry,
        103,
        42);

    TEST_ASSERT_EQUAL_UINT8(
        42,
        device.data[3]);

    TEST_ASSERT_EQUAL_UINT32(
        3,
        device.last_address);

    TEST_ASSERT_EQUAL_UINT8(
        42,
        device.last_value);

    TEST_ASSERT_EQUAL_UINT8(
        1,
        device.write_count);
}