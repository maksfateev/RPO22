from src.pricing import calculate_total, parse_coupon


def test_calculate_total_without_discount() -> None:
    items = [
        {"name": "Keyboard", "price": 100.0, "qty": 2},
        {"name": "Mouse", "price": 50.0, "qty": 1},
    ]
    assert calculate_total(items) == 250.0


def test_calculate_total_with_loyalty_and_bulk_discount() -> None:
    items = [
        {"name": "Monitor", "price": 300.0, "qty": 4},
    ]
    # subtotal = 1200, loyalty discount = 10%, plus bulk discount 5%
    assert calculate_total(items, loyalty_points=100) == 1026.0


def test_parse_coupon() -> None:
    assert parse_coupon("WINTER:15") == ("WINTER", 15)
