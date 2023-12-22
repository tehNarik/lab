namespace DA_LR5;

public class ItemGenerator
{
    public List<Item> Generate(int numItem, int maxWeight, int maxCost)
    {
        Random random = new Random();
        List<Item> items = new List<Item>();
        for (int i = 0; i < numItem; i++)
        {
            items.Add(new Item(random.Next(1, maxWeight), random.Next(2, maxCost)));
        }

        return items;
    }
}