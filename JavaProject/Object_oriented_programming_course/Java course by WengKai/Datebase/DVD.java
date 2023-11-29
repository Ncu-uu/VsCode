package Datebase;
public class DVD extends Media
{
    private String director;

    public DVD(String artist, String titile, String comment, String director) {
        super(artist, titile, comment);
        this.director = director;
    }
    public void print()
    {
        System.out.print("DVD:");
        super.print();
        System.out.println(director);
    }
}
