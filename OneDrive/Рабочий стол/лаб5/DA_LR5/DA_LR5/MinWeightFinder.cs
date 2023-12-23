namespace DA_LR5;

public class MinWeightFinder
{
    public int Find(List<Item> items)
    {
        int minWeight = int.MaxValue;
        for (int i = 0; i < items.Count; i++)
        {
            if (minWeight > items[i].Weight)
            {
                minWeight = items[i].Weight;
            }
        }

        return minWeight;
    }
}