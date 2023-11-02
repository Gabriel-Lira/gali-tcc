#include "communication/physical/physical.h"

bool phy_layer_initialize(PhysicalLayerContext *ctx)
{
    return ctx->physical_driver->initialize(ctx);
}

bool phy_layer_is_busy(PhysicalLayerContext *ctx)
{
    return ctx->physical_driver->is_busy(ctx);
}

bool phy_layer_set_enable(PhysicalLayerContext *ctx, bool state)
{
    bool was_successful_exec = ctx->physical_driver->set_enable(ctx, state);

    if (was_successful_exec)
    {
        ctx->is_enabled = state;
    }

    return was_successful_exec;
}

bool phy_layer_read(PhysicalLayerContext *ctx, uint8_t *buffer, size_t n_bytes)
{
    return ctx->physical_driver->read(ctx, buffer, n_bytes);
}

bool phy_layer_write(PhysicalLayerContext *ctx, const uint8_t *buffer, size_t n_bytes)
{
    return ctx->physical_driver->write(ctx, buffer, n_bytes);
}
