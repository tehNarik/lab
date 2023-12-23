namespace DA_LR5;

public class Item
{
    public int Weight { get; }
    public int Cost { get; }

    public Item(int weight, int cost)
    {
        Weight = weight;
        Cost = cost;
    }
    
    public Item(string info)
    {
        string[] splitInfo = info.Split();
        Weight = int.Parse(splitInfo[0]);
        Cost = int.Parse(splitInfo[1]);
    }

    public double Nectar()
    {
        return (double)Cost / Weight;
    }
}