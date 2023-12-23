namespace DA_LR5;

public class ScoutsSendler
{
    public List<int> Send(int scouts, List<Item> items)
    {
        Random random = new Random();
        List<int> randomItems = new List<int>();
        List<int> itemsIndexes = new List<int>(Enumerable.Range(0, items.Count));
        while (scouts > 0 && itemsIndexes.Count != 0)
        {
            int randomIndex = random.Next(0, itemsIndexes.Count);
            randomItems.Add(itemsIndexes[randomIndex]);
            itemsIndexes.RemoveAt(randomIndex);
            scouts--;
        }

        return randomItems;
    }
}