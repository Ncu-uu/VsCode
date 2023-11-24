public class TV
{
    boolean on = false;
    int channel = 1;
    int volumeLevel = 0;

    public TV()
    {

    }

    public void turnOn()
    {
        on = true;

    }

    public void turnOff()
    {
        on = false;
    }

    public void setChannel(int newChannel)

    {
        channel = newChannel;
    }

    public void setVolumeLevel(int newVolumeLevel)
    {
        volumeLevel = newVolumeLevel;
    }

    public void channelUp()
    {
        channel++;
    }

    public void channelDown()
    {
        channel--;
    }

    public void volumeLevelUp()
    {
        volumeLevel++;
    }

    public void volumeLevelDown()
    {
        volumeLevel--;
    }

}
