# Codex Review Playground

Этот репозиторий создан как «песочница» для проверки качества code review от Codex.

## Что внутри
- Небольшой Python-проект (`src/`).
- Набор unit-тестов (`tests/`).
- GitHub Actions workflow для автоматического запуска тестов.
- Файл с задачами для ревью (`REVIEW_TASKS.md`).

## Быстрый старт
```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements-dev.txt
pytest -q
```

## Как использовать для оценки code review
1. Внесите изменения в код (или используйте уже существующие спорные места из `REVIEW_TASKS.md`).
2. Попросите Codex сделать code review.
3. Сравните найденные проблемы с ожидаемыми из `REVIEW_TASKS.md`.

## Структура
```text
.
├── .github/workflows/ci.yml
├── REVIEW_TASKS.md
├── requirements-dev.txt
├── src
│   ├── __init__.py
│   ├── pricing.py
│   └── storage.py
└── tests
    ├── test_pricing.py
    └── test_storage.py
```
