import processing.core.PApplet;

public class Main extends PApplet {
    
    final int MAX_LEVEL = 8;
    public void settings() {

    }

    public void setup() {
        fullScreen();
        noStroke();
    }

    public void draw() {
        background(0);
        drawRecursiveSquare(0, width / 2, height / 2, 255f);
    }
    void drawRecursiveSquare(int n, float xc, float yc, float r, float c){
        if(n < MAX_LEVEL){
            drawRecursiveSquare(n + 1, xc - r, yc - r, r / 2, c - 250 / MAX_LEVEL);
            drawRecursiveSquare(n + 1, xc + r, yc - r, r / 2, c - 250 / MAX_LEVEL);
            drawRecursiveSquare(n + 1, xc + r, yc + r, r / 2, c - 250 / MAX_LEVEL);
            drawRecursiveSquare(n + 1, xc - r, yc + r, r / 2, c - 250 / MAX_LEVEL);
            fill(255f, 0f, 0f);
            square(xc - r, yc - r, 2 * r);
        }
    }
    public static void main(String[] args) {
        PApplet.main(Main.class);
    }
}


