## Creating image data

Generate palette of faces and facial components (hair, eyes, accessories, skin tone) several ways:

### Generation

- https://thispersondoesnotexist.com/
- img2img (local or https://huggingface.co/spaces/huggingface/diffuse-the-rest)
- freely available resources e.g. world map imagery, automobile profiles, etc.

### Getting the colors right

- `convert infile.png -resize 80x80 +dither -remap Windows_16colors_palette.png outfile.png`
- `convert infile.png -resize 80x80 -remap Windows_16colors_palette.png outfile.png`
- GIMP: scale image, Image>Mode>Indexed>Use custom palette>Default(23) (then further downsample the greys and dark purple)
  - alternatively, create an accurate C. A. palette
  - use the various dithering algorithms (normal, reduced bleeding, positional, etc.)
- once an assortment of faces is constructed, perhaps create a majority/complexity algorithm that chooses color values based on (1) most used color, and (2) differs from neighboring pixels in tiebreaking cases

### What next

- depending on the details of the original engine (to be examined) facial components might need to be separated and saved to create random, composite faces later. If this is really how the engine works, we have to see how the color values work.
- compress using the same method as the original data files

## Creating a soundtrack

How to replace such an iconic track? Well, we certainly cannot rip off the original artwork, but there are themes from thrillers that have a driving beat (Cannon, Ironside), minor key with chromatic shifting (James Bond, The Streets of San Francisco, Barnaby Jones), powerful polyphony (Magnum, P.I., Police Story), and other musical structure similar to the Covert Action theme.

Furthermore, we can consider soundtracks from many of the 80s and 90s Roland-era MS-DOS games: Space Quest, The Secret of Monkey Island, DOOM, and so many more.

Couple all that with some Broadway inspiration (Curtains, Clue, Baker Street, The Mystery of Edwin Drood) and we are sure to have a lot of material as inspiration.
