from __future__ import annotations


def calculate_total(items: list[dict], loyalty_points: int = 0) -> float:
    """Calculate order total.

    Expected item format:
    {"name": str, "price": float, "qty": int}
    """
    subtotal = 0.0
    for item in items:
        subtotal += item["price"] * item["qty"]

    discount = min(loyalty_points / 1000, 0.2)
    total = subtotal * (1 - discount)

    if subtotal > 1000:
        total = total * 0.95

    return round(total, 2)


def parse_coupon(raw: str) -> tuple[str, int]:
    """Parse coupon in format CODE:PERCENT."""
    code, percent = raw.split(":")
    return code.strip(), int(percent)
