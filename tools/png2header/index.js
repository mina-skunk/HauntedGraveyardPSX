const fs = require("fs");
const PNG = require("png-js");

const args = process.argv.slice(2);

const inImage = PNG.load(args[0]);

const width = inImage.width;
const height = inImage.height;

let outText = "\r\n#define " + args[1] + "_WIDTH " + width + "\r\n" + "#define " + args[1] + "_HEIGHT " + height + "\r\n\r\nconst unsigned short " + args[1] + "[] = {";

inImage.decode(function (pixels) {
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
  fs.writeFile(args[2], outText, function (err) {
    if (err) console.error(err);
  });
});
