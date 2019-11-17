'''
MIT License

Copyright (c) 2019 Hyeonki Hong <hhk7734@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
'''

from setuptools import setup, Extension
from setuptools.command.sdist import sdist
from setuptools.command.build_py import build_py
from os import path

BASE_DIR = path.dirname(path.abspath(__file__))
CHANGELOG_PATH = path.join(BASE_DIR, "debian/changelog")

ext_modules = [
    Extension(
        "lot._lot",
        sources=["wrap/lot.i"],
        libraries=["lot"],
        swig_opts=["-c++",
            "-I/usr/local/include",
            "-I/usr/include"]
    ),
]

with open(CHANGELOG_PATH, "r") as f:
    version = f.readline()
    version = version.split()
    version = version[1][1:-1]

'''
for upload
'''
class sdist_after_ext(sdist):
    def run(self):
        self.run_command("build_ext")
        return sdist.run(self)

'''
in the distribution when running setup.py bdist or bdist_wheel.
'''
class build_py_after_ext(build_py):
    def run(self):
        self.run_command("build_ext")
        return build_py.run(self)

setup(
    version = version,
    ext_modules = ext_modules,
    cmdclass = {"sdist": sdist_after_ext,
                "build_py": build_py_after_ext},
)
