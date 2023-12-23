namespace DA_LR5;

public static class InputHiveValidationContext
{
    public static Dictionary<string, string> Validate(string input, int size)
    {
        NumberEntriesValidator numberEntriesValidator = new NumberEntriesValidator();
        IsNumberValidator isNumberValidator = new IsNumberValidator();
        numberEntriesValidator.SetSuccessor(isNumberValidator);
        CorrectNumberValidator correctNumberValidator = new CorrectNumberValidator();
        isNumberValidator.SetSuccessor(correctNumberValidator);

        return numberEntriesValidator.HandleValidation(input, size); 
    }
}