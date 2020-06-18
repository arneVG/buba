import setuptools

setuptools.setup(
    name="buba",
    version="0.0.1",
    author="Arne van Gestel",
    description="Backup tool for Budgie",
    url="https://github.com/arneVG/buba",
    packages=["buba"],
    install_requires = [
        'pygobject'
    ],
    entry_points = {
        "console_scripts": ["buba=buba.buba:main"]
    }
)