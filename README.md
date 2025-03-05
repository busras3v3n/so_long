# so_long

![Screenshot from 2025-02-26 12-00-48](https://github.com/user-attachments/assets/70eedb71-b744-4306-a3af-b11031d7ac3f)

so_long is a game project in C, developed using the library [minilibx](https://github.com/42Paris/minilibx-linux).<br>
As someone who loves games and art, it was a really fun project to work on.<br>
I've drawn all the assets except for [these](./bonus/counter_img) which I got as a font from [this site](https://fontmeme.com/pixel-fonts/).<br>
You can use my assets in your own so_long project as long as you give credit and a link to my repository.<br>

## ![browncatright](https://github.com/user-attachments/assets/6177aecf-4905-4eae-b3be-8b725d97ac7c) Bonus

The bonus version, in addition to all the mandatory features has:<br>
- Movement count on the top left corner of the screen,<br>
- Enemy patrols which will reset the level if you happen to bump into them,<br>
- And sprite animation for enemies.<br>

### ![whitecat](https://github.com/user-attachments/assets/ccc8cdbd-36a1-42fa-86c6-069e47ae2c05) Execution
first you need to clone the minilibx-linux library in the project repository.<br>
`git clone https://github.com/42paris/minilibx-linux.git minilibx-linux`<br><br>
`make` to compile mandatory<br>
`make bonus` to compile bonus<br><br>
execute `./so_long ./maps/test.ber` for the default map.<br>
execute `./so_long ./bonus/maps/test.ber` for the default bonus map.<br>
you can replace the default map with any .ber file of your choice.<br><br>

![rabbitaftercarrot](https://github.com/user-attachments/assets/3cd58d3e-a04a-4183-bf6c-1d1793e6bfd3)

### Gameplay

`W, A, S, D` for movement<br>
`R` to re-play<br>
`esc` exits the program.<br>
You win by collecting all collectibles and running to the exit.<br>
