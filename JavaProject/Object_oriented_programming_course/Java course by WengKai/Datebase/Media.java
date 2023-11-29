package Datebase;

public class Media {
    private String artist;
    private String titile;
    private String comment;

    public Media(String artist, String titile, String comment) {
        this.artist = artist;
        this.titile = titile;
        this.comment = comment;
    }

    public void print() {
        System.out.print(artist + " " + titile + " " + comment + " ");
    }
}


