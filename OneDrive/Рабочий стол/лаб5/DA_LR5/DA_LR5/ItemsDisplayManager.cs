namespace DA_LR5;

public class ItemsDisplayManager
{
    public void Manage(List<Item> items)
    {
        MassageWriter.Write(Massages.DisplayItems);
        bool correctEnter = false;
        string input = string.Empty;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            if (input == "1")
            {
                MassageWriter.Write(Massages.DisplayItemsExample);
                Display.Items(items);
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