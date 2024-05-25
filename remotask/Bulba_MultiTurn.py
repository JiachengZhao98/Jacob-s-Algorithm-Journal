import string
import random

def generate_password(length):
    """
    Generates a random password with uppercase, lowercase, numbers, and special characters,
    with a minimum length of 6.

    Args:
        length: The desired length of the password (must be at least 6).

    Returns:
        A string representing the generated password.

    Raises:
        ValueError: If the requested length is less than 6.
    """

    if length < 6:
        raise ValueError("Password length must be at least 6 characters.")

    # ... (rest of the code remains the same)
    # ...

# Example usage with minimum length enforced
try:
    password = generate_password(3)  # Will raise an error
except ValueError as e:
    print("Error:", e)

password = generate_password(12)
print(password)  # Example output: i69D@&,9@czm
