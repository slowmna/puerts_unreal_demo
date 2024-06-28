

import * as UE from 'ue';
import {NewObject} from "ue";


console.log("QuickStart! Begin!");
function Foo() {
    let Obj = UE.JSBlueprintFunctionLibrary.GetTestOuter();
    Obj.DoSomething();

    const StructA = Obj.ReturnConstRef();
    UE.JSBlueprintFunctionLibrary.TouchTestA(StructA)
    UE.JSBlueprintFunctionLibrary.TouchTestA(StructA)

    let cnt1 = 0;
    let cnt1ShouldBe = StructA.MyTestB.Num();
    for (let [k, v] of StructA.MyTestB) {
        cnt1 = cnt1 + 1;
        let cnt2 = 0;
        let cnt2ShouldBe = v.MyDummy.Num();
        for (let iter of v.MyDummy) {
            cnt2 = cnt2 + 1;
            // let NoUse = NewObject(UE.DummyObj.StaticClass())
        }

        if (cnt2 != cnt2ShouldBe) {
            console.error(`cnt2 Num wrong! ShouldBe:${cnt2ShouldBe} now: ${cnt2}`)
        }

        globalThis.FullGC();
    }

    if (cnt1 != cnt1ShouldBe) {
        console.error(`cnt1 Num wrong! ShouldBe:${cnt1ShouldBe} now: ${cnt1}`)
    }
}

setInterval(()=>{
    Foo();
}, 3000)

console.log("QuickStart! Done!")