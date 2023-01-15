import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

/**
 * Created by eXetrum on 31.10.2016.
 */
public class Mandelbrot {
    private int height;
    private int width;
    private BufferedImage img;

    public Mandelbrot(int height, int width) {
        this.height = height;
        this.width = width;

        img = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
    }

    // Generate Julia set and save to file
    public boolean generateToFile(String filename) {
        try {
            File outputFile = new File(filename);
            // Min/max range on complex plane
            ComplexNumber rangeMin = new ComplexNumber(-2.0, -2.0);
            ComplexNumber rangeMax = new ComplexNumber(2.0, 2.0);
            // Incremental values for Real, Imaginary parts
            double dr = (rangeMax.getR() - rangeMin.getR()) / width;
            double di = -(rangeMax.getI() - rangeMin.getI()) / height;
            // Loop over image pixels
            for (int y = 0; y < height; ++y) {

                for (int x = 0; x < width; ++x) {
                    ComplexNumber c = new ComplexNumber
                    (
                            x * dr + rangeMin.getR(),
                            y * di + rangeMax.getI()
                    );
                    ComplexNumber z = new ComplexNumber(0, 0);
                    // Mandelbrot set calculation
                    int n = 255;
                    while (n >= 5 && z.mag() < 2) {
                        z = z.mult(z).add(c);
                        n -= 5;
                    }
                    // Set output pixel value
                    //Color pixel = new Color( ((int)Math.abs(n * Math.sin(n))) % 256, n * 3 % 256, n % 256);
                    Color pixel = new Color(n % 256, n % 256, n % 256);
                    img.setRGB(x, y, pixel.getRGB());
                }
            }


            ImageIO.write(img, "png", outputFile);
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
