

April 04 16 2025

finally killed the constant initializer error thing, just had to move the `gameplayLineStartpoint` to InitGameplayScreen() function in the screen_gameplay.c file. Now my new issue is that the second variable y isn't get accounted to. like what the fuck
:w
figured out i just have to do gameplayLineStartpoint.x thing, i forgor the { 0, 0 } was just for initialing

2:14 pm

* fixed barline finally on center
* added playfield Line that expands before gameplay 
>   this one was very stupid, i had to refix my thinking and realized that Draw() and Update() have different timings. So if you want to "draw" in the screen then you're off putting that increment on the Draw(), if it needs fast calculation then it must be on Update().
* made window resizable

# introduced new bugs! (yey)

now the box stops moving due to the fact window is resizable now, the box depends on GetWindowWidth() to move, now its fucked!

to work in future:
* timings (make it invincible to speedhacking via SDL_getns())

4:04 PM

* fixed playfield + it follows initial WindowWidth size
>   problem is it can't backtrack itself, nor draw more once rendering finished

TODO!
>   Initial implementation of SpawnHitObject(), MoveHitObject(), DestroyHitObject(), PlayerHitArea(), ObjectHitArea()

April 17 2025
3:55 PM
initial implementation of DrawHitObject(), MoveHitObject(), FreeHitObject()


GOD HOLY SHIT I WENT DEEP WITH MULTI C FILES. It was the hellish experience to figure out how to actually share variables inside a header file.

first i was like what the fuck why dis aint sharing variables, i got to the point beefing with chatgpt on how variables work between files, turns out i was just stupid, the flow is 

write a variable in .h file -> initalize it somewhere -> variable is accessable in other c file. IT WORKS!- no not really, the linker still complains.

i figured out maybe to use the #ifdef guard, used it and YEY!! The error is fucking on color now! Progress!

I figured maybe hey, maybe i just need to move this variables in a single .g file, i did and nada, no nothing.

I was about to give up when i realized maybe i need to put it outside the function, sounds stupid since doing that caused a massive issue functions having difficulty to read the value. AND OH MY GOD THE FUCKING GAME LAUNCHES AGAIN, BUT IT CRASHES IN GAMEPLAY SCENE ARGHHH!!! oh.. its just the for loop having out of bound number against the initialized array, silly me!

it works now, my god but this shit need lots of fucking rework. the bar is missing now, i still need to test if the functions work correctly. I MEAN WRITE THE FUNCTIONS correctly. might as well write a test scene i guess?

TODO:
* make functions.. functional, duh

7:03 problem

ok figured things out why the the linebar wont move, its because IM FUCKING INITIALIZING THE VARIABLE ON FUCKING ON DRAW, AMAZING

8:25 pm 

did a simple primitive delay to test whether things works as expected:

## Expectation:
multiple bars appear, scattering around the playfield thanks to different speeds set randomly

## Actual behavior:
once the delay ends, the bar stays in the edge, the position doesnt change.

meaning i'm doing something wrong, its most likely i really need that PrepareHitObject() function or just merge both of it to DHO. but i already did overtime now, i dont want to burn myself out. so i'll be taking my off


April 18 2025

9:15 pm

fixed by shuffling around functions, no fucking idea how that worked.

anyways i have started working on PlayerHitArea. 

April 19 2025

1:57 AM 

i feel an intense embarassment to myself. LIKE HOLY CRAP ALL ALONG WHTA I NEEDED WAS `DrawRectangleLines()` all along in my gameplayLineStartpoint, its so fucking stupid and i want to kms holy shit agrhhhhhh.

so my end goal is to rewrite all gameplayLineStartpoint with something much more sane. 
