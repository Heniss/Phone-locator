# Phone-locator

## Inspiration
Visual impairment is prevalent. In the United Kingdom, over 2 million people live with sight loss. Among these, approximately 340,000 are registered as blind or partially sighted. In the United States, the figure is significantly higher, exceeding 12 million individuals aged 40 and older, of whom 1 million are completely blind.

Modern technology assists both visually impaired and blind individuals in various aspects, beginning with VoiceOver, an application that reads mobile phone contents, and extending to devices such as liquid level indicators to prevent spillage. However, an unresolved issue persists: what can a visually impaired person do when their cell phone battery dies? While charging the phone may not pose a challenge when living with family or a partner, locating it can be problematic. This issue is especially acute for blind individuals living independently. Although It is not a problem if our phone dies in a purse or backpack, it is in case when one is home alone and forgets where one has put it. Since it is common knowledge that one cannot call a dead phone, the only recourse is to expend time searching for it. 

## General construction of the project
My proposed solution to this predicament involves installing a sound-activated buzzer on the back of the phone. Given the ubiquity of wireless charging technology, the device's battery would be affixed to the rear cover with a magnet, allowing simultaneous charging with the phone battery. With minimal power consumption, this secondary battery could operate for over 72 hours without requiring recharging.

The design for this device is straightforward. A copper coil is centrally positioned within the gadget, functioning as a wireless charger receiver through a bridge rectifier, charging the HHS-18013 5V battery situated nearby. The ESP8266 serves as the main controller due to its compact size. Additionally, a sound sensor, small buzzer, and capacitors for spike filtration and output voltage regulation are necessary.

Although the input voltage from the receiver coil is approximately ~5.2V, the AMS1115 regulator ensures a consistent output of no more than 5V. 

The back and side view is visualized in **‘visualization.png’** file. The circuit diagram for the entire project **‘circuit_diagram.pdf’**, along with the required components **‘circuit_parts.png’**, is provided. The necessary code for the project is included in the **'main.cpp'** file, which is pre-installed on each device. 
Visual representation of the project is in **‘video.mov’** file.

A specially programmed sound sensor detects clapping sounds, triggering the buzzer if two claps are recorded within 200 milliseconds. Subsequently, the buzzer emits three 4kHz tones, each lasting one second. 

Consequently, visually impaired or blind individuals can easily locate their discharged phones through auditory cues.

The advantages of this project include:
- Cost-effectiveness with each device priced at less than $5 when purchased, in wholesale quantities.
- Minimal size, ensuring inconspicuous daily use.
- High volume output, reaching up to 80 dB.
- Adjustable clap detection sensitivity using a screwdriver, allowing individual customization for each user.

![Visaulization](/visualization.png)
![Circuit parts](/circuit_parts.png)
![Circuit diagram](/circuit_diagram.pdf)

