namespace DA_LR5;

public class UsedItemsDisplayManager
{
    public void Manage(List<Item> items, List<int> usedItems)
    {
        MassageWriter.Write(Massages.DisplayUsedItems);
        bool correctEnter = false;
        string input = string.Empty;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            if (input == "1")
            {
                Display.UsedItems(items, usedItems);
                correctEnter = true;
            }
            else if (input == "2")
            {
                correctEnter = true;
            }
            else
                MassageWriter.Write(Massages.IncorrectInput);
        }
    }
}