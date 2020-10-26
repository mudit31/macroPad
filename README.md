# Introduction

I created this "macropad" as at work, I was constantly getting told that I am stepping away from my computer without locking it. I am aware that this is bad hygiene, but I am also exceedingly lazy. The main reason I did this was because on MacOS, there is no easy shortcut to lock the computer. This is especially true with MacBooks with non-US keyboard layout. 

I wanted to create a button that I could easily push, and it would lock my computer. I drooled over the [Steak Deck](https://www.amazon.de/dp/B06W2KLM3S/), but was put off by its cost.

Having built an [Ergodox](https://www.ergodox.io/) keyboard from scratch a few years ago, I decided to give making a macropad a go.

# Parts required

1. Access to a 3d printer for case. I own a [ANYCUBIC i3 Mega S](https://www.amazon.de/dp/B07KCGN34W), and used that. It is a very basic 3d printer that requires a good amount of TLC to keep printing. But it is cheap and a decent "starter" printer. I have mine hooked up with [OctoPrint](https://octoprint.org) running on a [Raspberry Pi 3 Model B](https://www.raspberrypi.org/products/raspberry-pi-3-model-b) together with a cheap webcam and [Spaghetti Detective](https://www.thespaghettidetective.com).

1. Cherry compatible key switches. Here, you can go crazy. I ordered mine from [CANDYKEYS](https://candykeys.com/category:switches). Personally, I prefer [Cherry MX Blue](https://candykeys.com/product/cherry-mx-blue-plate-m).

1. Keycaps. I ordered mine from [AliExpress](https://de.aliexpress.com/). Any of the suppliers will do; just make sure they are cherry-compatible. Personally, I ordered a bunch of [random colors from this seller](https://de.aliexpress.com/item/4000480076757.html). Mine took about a month to arrive.

1. Soldering iron. I used [this cheap one](https://www.amazon.de/-/en/gp/product/B07WYLF6QV/). Any would do, just be careful with it.

1. Any micro-usb cable.

1. [Arduino Pro Micro 5v/16MHz](https://www.sparkfun.com/products/12640). A good guide that I referred to constantly during this project is their excellent [Hookup Guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide). I bought mine from [CANDYKEYS](https://candykeys.com/product/pro-micro-5v-16mhz).

# Instructions
1. Print the case. I sketched mine using [Trimble Sketchup](https://app.sketchup.com/app?hl=en), and exported to STL. I used [CURA](https://ultimaker.com/software/ultimaker-cura) to slice and generate the `.gcode` file.

Cabling diagram and instructions are WIP. Basically, following instructions from the  [Hookup Guide](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide), one pin of all the switches were soldered in series to ground. The second pin was soldered to the numbered IO pins of Pro Micro.