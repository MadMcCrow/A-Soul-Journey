# A Soul journey

A Soul journey is a ARPG prototype in godot

## Godot project

This project is made with the Godot Engine (here pronounced _/ˈɡɒdoʊ/_ _GOD-oh_) built from source with a `custom.py` file passing arguments to `scons` (the build tool).

### Setup on your device

to set the project up on your device just clone this repository and run the following:
   
```
git submodule update --init --recursive # update/get the godot submodule
make # or python build/setup.py
```
if this does not work for you, I suggest you check [`build/config.json`](build/config.json) and [`build/custom.py`](build/custom.py) to see if anything is not compatible with your current configuration.


### prototyping approach

The game is made with gdscript, c++, visual scrputing and everything in between, in order to prototype as fast as we can.

## Help and Participate.

Any push request will be treated, and merged if it's any kind of improvement or bug fix.
You can also fork this project and make a game of your own.

## git emoji table used : 

we try to use emojis to make changes more meaningful and easily identify them

| emoji             | commit contains               |
| ------------------|:-----------------------------:|
| :zap:             | improvement                   |
| :construction:    | WIP                           |
| :art:             | graphical asset               |
| :wrench:          | update build system           |
| :no_entry_sign:   | does not compile / launch     |
| :page_facing_up:  | update of doc, licence, etc.  |
| :bug:             | bug fix                       |
| :leaves:          | scene update                  |
| :up:              | tool / godot upgrade          |
| :vs:              | vs code specific changes      |


## License

Copyright © Noé Perard-Gayot 2021.    
Licensed under the [MIT License](LICENSE.txt)
You may also obtain a copy of the License at https://opensource.org/licenses/mit-license.php 
