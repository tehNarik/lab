namespace DA_LR5;

public class FinalCalculate
{
    public int Weight(List<Item> items, List<int> usedItems)
    {
        int totalWeight = 0;
        for (int i = 0; i < usedItems.Count; i++)
        {
            totalWeight += items[i].Weight * usedItems[i];
        }

        return totalWeight;
    }
    
    public int Cost(List<Item> items, List<int> usedItems)
    {
        int totalCost = 0;
        for (int i = 0; i < usedItems.Count; i++)
        {
            totalCost += items[i].Cost * usedItems[i];
        }

        return totalCost;
    }
}