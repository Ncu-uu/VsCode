package Datebase;

import java.util.ArrayList;

public class Datebase {
    private ArrayList<Media> ListMedia = new ArrayList<Media>();

    public void add(Media listmedia)
    {
        ListMedia.add(listmedia);
    }

    public void list()
    {
        for(Media media : ListMedia)
        {
            media.print();
            System.out.println();
        }
    }

    public static void main(String[] args)
    {
        Datebase db = new Datebase();
        db.add(new CD("abc","def","ghi",1));
        db.add(new DVD("aaa","bbb","ccc","ddd"));
        db.list();


    }
}
