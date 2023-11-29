package Datebase;
public class CD extends Media {
    private int numoftracks;

    public CD(String artist, String titile, String comment, int numoftracks) {
        super(artist, titile, comment);
        this.numoftracks = numoftracks;
    }

    public void print() {
        System.out.print("CD:");
        super.print();
        System.out.println(numoftracks);
    }
}
