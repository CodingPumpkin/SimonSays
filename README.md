# SimonSays
## Motivation
I want to make a simple game to get to know SDL a little better. Also I really love Simon Says. Don't know what it says about me :)

## Notes:
- While making this project I came across an interesting error. I thought it would be nice to share it here in cas I forget how to fix it. When I added `logic.h` and `logic.c` files I described the `game_state_struct` in one the header file and made a pointer to it. Then I defined the functions I wanted. The program compiled successfully. But when I tried to include `logic.h`  into `main.c` I got this error reading 
```/usr/bin/ld: /tmp/ccAyer4V.o:(.bss+0x20): multiple definition of `p_game_state'; /tmp/ccKrapNs.o:(.bss+0x0): first defined here
collect2: error: ld returned 1 exit status```
Naturally, I figured it was about include guards or what not. But include guard were okay. Moreover `#pragma once` gave the very same result. This error is consistent with my versions of gcc (14.2.1) and ld (2.43.0). The way I solved this problem was separating the declaration of the struct and declaration of its fields. Thus the header file now only contains one line `struct game_state_struct;` and the `.c` file contains the full description.
It seems like another workaround would be using typedef but I did not manage to get it to work either. And since I am not that big of a typedef fan I did not bother to look any further.
