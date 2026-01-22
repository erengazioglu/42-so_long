# so_long | Notes

## Images: MAGICK

```bash
for file in assets/*.bmp; 
do magick "$file" "${file%.png}.xpm"; 
done
```