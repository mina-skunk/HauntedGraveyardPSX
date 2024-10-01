const fs = require("fs");
const { program } = require('commander');

program.command("texture")
  .description("Converts PNG to 16bit RGB5A1 texture")
  .argument("<in>", "png image file")
  .option("-n, --name <name>", "name used for const")
  .argument("<out>", "texture as header file")
  .action((_in, _out, options) => {
    const PNG = require("png-js");

    const inImage = PNG.load(_in);

    const width = inImage.width;
    const height = inImage.height;

    let outText = "\r\n#define " + options.name + "_WIDTH " + width + "\r\n" + "#define " + options.name + "_HEIGHT " + height + "\r\n\r\nconst unsigned short " + options.name + "[] = {";

    inImage.decode((pixels) => {
      // pixels is a 1d array (in rgba order) of decoded pixel data
      for (let y = 0; y < height; y++) {
        outText += "\r\n    ";
        for (let x = 0; x < width; x++) {
          const i = y * width * 4 + x * 4;

          const r5 = pixels[i] >> 3;
          const g5 = pixels[i + 1] >> 3;
          const b5 = pixels[i + 2] >> 3;
          const a1 = pixels[i + 3] >> 7;

          const tim_pixel = r5 + (g5 << 5) + (b5 << 10) + (a1 << 15);

          outText += "0x" + tim_pixel.toString(16) + ", ";
        }
      }
      outText += "\r\n};\r\n";
      fs.writeFile(_out, outText, (err) => {
        if (err) throw err;
      });
    });
  });

program.command("tilemap")
  .description("Converts Tiled tilemap to binary map data")
  .argument("<in>", "xml Tiled tilemap")
  .option("-n, --name <name>", "name used for const")
  .option("-l, --layer <layer>", "layer to read from Tiled tilemap", 0)
  .argument("<out>", "tilemap as header file")
  .action((_in, _out, options) => {
    const tmx = require('tmx-parser');

    tmx.parseFile(_in, (err, map) => {
      if (err) throw err;

      const width = map.width;
      const height = map.height;

      let outText = "\r\n#define " + options.name + "_WIDTH " + width + "\r\n" + "#define " + options.name + "_HEIGHT " + height + "\r\n\r\nconst unsigned char " + options.name + "[] = {";

      for (let y = 0; y < height; y++) {
        outText += "\r\n    ";
        for (let x = 0; x < width; x++) {
          const i = y * width + x;

          const tile = map.layers[options.layer ? parseInt(options.layer) : 0].tiles[i];

          if (tile) {
            outText += tile.gid + ", ";
          } else {
            outText += "0, ";
          }
        }
      }

      outText += "\r\n};\r\n";
      fs.writeFile(_out, outText, (err) => {
        if (err) throw err;
      });
    });
  });

program.parse();
