#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_PHYSICAL_PHYSICAL
#define SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_PHYSICAL_PHYSICAL

#include "communication/stack/layer/layer.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PhysicalLayerContext PhysicalLayerContext;

typedef struct PhysicalLayerDriver
{
    bool (*initialize)(PhysicalLayerContext *);
    bool (*is_busy)(PhysicalLayerContext *);
    bool (*set_enable)(PhysicalLayerContext *, bool);

    bool (*read)(PhysicalLayerContext *, uint8_t *buffer, size_t n_bytes);
    bool (*write)(PhysicalLayerContext *, const uint8_t *buffer, size_t n_bytes);

} PhysicalLayerDriver;

struct PhysicalLayerContext
{
    CommLayerCtx super;

    const PhysicalLayerDriver *physical_driver;

    bool is_enabled;
};

bool phy_layer_initialize(PhysicalLayerContext *);
bool phy_layer_is_busy(PhysicalLayerContext *);
bool phy_layer_set_enable(PhysicalLayerContext *, bool);
bool phy_layer_read(PhysicalLayerContext *, uint8_t *buffer, size_t n_bytes);
bool phy_layer_write(PhysicalLayerContext *, const uint8_t *buffer, size_t n_bytes);

#ifdef __cplusplus
}
#endif

#endif