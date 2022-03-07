local function rgba(r, g, b, a)
  a = a or 1.0

  return {
    red = r / 255,
    green = g / 255,
    blue = b / 255,
    alpha = a
  }
end

-- Define your layers here, as well as the foreground/background of the
-- layer indicator.
--
-- see http://colorsafe.co for some color combos
local layers = {
  default = {
    name = "Base Layer",
    background = rgba(187, 187, 187),
    foreground = rgba(46, 52, 59),
  },
  layer1 = {
    name = "Layer 1",
    background = rgba(163, 209, 255),
    foreground = rgba(46, 52, 59),
  },
  layer2 = {
    name = "Layer 2",
    background = rgba(163, 255, 163),
    foreground = rgba(46, 52, 59),
  },
  layer3 = {
    name = "Layer 3",
    background = rgba(255, 163, 163),
    foreground = rgba(46, 52, 59),
  },
}



-- load ~/.hammerspoon/layer-indicator.lua
local LayerIndicator = require "layer-indicator"

-- create a layer indicator
local indicator = LayerIndicator:new(layers.default)

-- intercept QMK keys to change the indicated layer
hs.hotkey.bind({}, 'f18', function()
  indicator:setLayer(layers.layer1)
end)

hs.hotkey.bind({}, 'f17', function()
  indicator:setLayer(layers.default)
end)

hs.hotkey.bind({}, 'f19', function()
  indicator:setLayer(layers.layer2)
end)

hs.hotkey.bind({}, 'f20', function()
  indicator:setLayer(layers.layer3)
end)
