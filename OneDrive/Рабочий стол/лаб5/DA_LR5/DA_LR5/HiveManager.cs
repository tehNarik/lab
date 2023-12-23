namespace DA_LR5;

public class HiveManager
{
    public void Manage(ref Hive hive)
    {
        HiveInput hiveInput = new HiveInput();
        Display.Hive(hive);
        MassageWriter.Write(Massages.ChangeHive);
        bool correctEnter = false;
        string input = string.Empty;
        while (!correctEnter)
        {
            input = Console.ReadLine() ?? string.Empty;
            if (input == "1")
            {
                hive = hiveInput.newHive();
                Display.Hive(hive);
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