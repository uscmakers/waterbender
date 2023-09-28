# Waterbender

Waterbender is a student-created art installation that is both dynamic and interactive. Using a built in webapp, user can create their own custom 2D designs, which are then displayed by dynamic streams of water.


![img_1](https://github.com/uscmakers/waterbender/assets/31314514/10e13fb9-68ab-40d8-9055-5ef34b16d7bb)


## Overview

Waterbender creates 2D designs with vertical streams of water. Each stream of water is controlled by an electric valve that is hooked up to our microcontroller. Our project is a fully independent, integrated system that automatically displays user inputted images, and regulates its own water levels using top and bottom water reservoirs, pumps, and water level sensors.

<img width="512" alt="Screenshot 2023-09-27 at 1 05 06 PM" src="https://github.com/uscmakers/waterbender/assets/31314514/0f976752-a76c-4818-978a-d302f6e33bff">


## Timeline
### Fall Semester
As is typically done in industry, we started off our design with a proof of concept, that had the core features we needed to make a minimum viable product:

<img width="404" alt="Screenshot 2023-09-27 at 1 08 08 PM" src="https://github.com/uscmakers/waterbender/assets/31314514/6e33486f-7971-4707-8cb1-435ec1e122b4">


This design only used 10 smaller solenoid valves, had simpler code, and was dwarved by our spring semester iteration:

<img width="584" alt="Screenshot 2023-09-27 at 1 09 16 PM" src="https://github.com/uscmakers/waterbender/assets/31314514/53e45d10-cf4d-4f88-a44b-29155a84e48a">


### Spring Semester
In our second and final semester, we used our learnings from the previous semester's proof of concept to scale our design. Our new design featured a number of improvements:
* much larger (standing at over 8 feet tall!) and sturdier wooden frame,
* **23** much larger (and more power hungry) solenoid valves,
* **leak free** water reservoirs (which is very important when all your high power electronics are housed next to them, this was a major challenge)
* pumps that recirculate water after it falls down, from the bottom reservoir back to the top reservoir
* **reliable** water level sensors that ensure that the pumps turn off when the top reservoir is full, so it doesn't overflow and destroy all our electronics
* more robust, easy to use webapp to draw custom designs and send them via https communications to our micrcontroller
* laser engraved wooden panels to hide the internals of our project
* electronics soldered onto protoboards (as opposed to breadboard) so that they are more reliable and connections are less likely to come loose

Since each column of water is requires one valve controlling it, we had 2.3x more resolution in the x direction than our previous 10 valve design, and since the vertical (y) dimension of the image depends on the vertical size of our display area, we had about 2x more vertical display area as well.

## Challenges

Since our project was so tall and our workspace was in the basement of a building, working on and moving the project was a constant struggle. Here are some highlights:

![IMG_0944](https://github.com/uscmakers/waterbender/assets/31314514/7e4fae2e-8ec8-46f2-8d52-272f45124599)

![IMG_0938](https://github.com/uscmakers/waterbender/assets/31314514/6c8fda2b-c7e2-4096-bfd4-c09b31867eca)


We all know that water and electronics don't mix well, and we narrowly avoided some catastrophic situations :)

## Technical Breakdown

## Acknowledgements
Special thank you to our team, Allan Weber, duct tape, and the very reliable EEB basement ladder.

![IMG_2538](https://github.com/uscmakers/waterbender/assets/31314514/fcbd51b1-e71e-4ffd-be5a-6d0f24e30a4b)


## Team Members
### Project Manager
Baran Cinbis
### Software Team
Pooja Kowshik, Akhilesh Bellathur
### Electrical Team
Evan Hashemi
### Mechanical Team
Aidan Leitch, Niusha Khoshsar, Victoria Pinkett
