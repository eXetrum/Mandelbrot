import javax.imageio.ImageIO;

/**
 * Created by eXetrum on 31.10.2016.
 */
public class testMain {
    public static void main(String args[]) {
        if(args.length != 3) {
            System.out.println("usage: <height> <width> <outfilename>\n");
            return;
        }
        
        int height = Integer.parseInt(args[0]);
        int width = Integer.parseInt(args[1]);


        Mandelbrot julia = new Mandelbrot(height, width);


        System.out.println("Generation: " + (julia.generateToFile(args[2]) ? " Success." : "Failure"));
    }
}
