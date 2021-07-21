"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const puerts_1 = require("puerts");
const cpp = require("cpp");
let TestClass = cpp.TestClass;
//static function
console.log(TestClass.Add(12, 34));
TestClass.Overload();
TestClass.Overload(1);
TestClass.Overload(1, 2);
TestClass.Overload("hello", 2);
//constructor
let obj = new TestClass();
obj = new TestClass(8, 9);
//method
obj.OverloadMethod();
obj.OverloadMethod(1024);
obj.OverloadMethod(4294967295);
obj.OverloadMethod(1024n);
//property
console.log(obj.X, obj.Y);
obj.X = 96;
obj.Y = 97;
console.log(obj.X, obj.Y);
obj.OverloadMethod();
//base method
obj.Foo(888);
//pass object
TestClass.PrintInfo(obj.GetSelf());
//ref
let r = puerts_1.$ref(999);
let ret = obj.Ref(r);
console.log("$unref:" + puerts_1.$unref(r) + ", ret:" + ret);
obj.ConstRef(999);
//# sourceMappingURL=CDataTest.js.map