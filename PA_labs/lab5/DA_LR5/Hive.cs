namespace DA_LR5;

public class Hive
{
    public int workers { get; }
    public int scouts { get; }

    public Hive( int workers, int scouts)
    {
        this.workers = workers;
        this.scouts = scouts;
    }
    
    public Hive( string info)
    {
        string[] splitInfo = info.Split();
        workers = int.Parse(splitInfo[0]);
        scouts = int.Parse(splitInfo[1]);
    }
}